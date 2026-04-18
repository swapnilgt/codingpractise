import java.util.logging.Level
import java.util.logging.Logger

enum class CircuitBreakerState {
    OPEN, CLOSED, HALF_OPEN
}

/**
 * @param errorThreshold The error count that acts as threshold to trigger the circuit OPEN
 * @param timeWindow The time-window within which the errors are measured. Window starts when the first error is
 * encountered.
 * @param timeout The timeout state before which the circuit has to be transitioned to HALF_OPEN state post it is OPEN.
 * @param successThreshold The consecutive success count
 */
class CircuitBreakerConfig(
    val errorThreshold: Int,
    val timeWindow: Long,
    val timeout: Long,
    val successThreshold: Int
)

class CircuitOpenException(): Exception()

class CircuitBreaker(
    private val config: CircuitBreakerConfig,
    private val relayService: RelayService,
    private val clock: Clock
) {

    // Circuit is initialised with closed state.
    private var state: CircuitBreakerState = CircuitBreakerState.CLOSED

    private var currErrorCount = 0
    private var errorTimeStart: Long = -1L
    private var circuitBrokenAt: Long = -1L
    private var successInHalfOpen = 0

    fun run(runnable: Runnable) {
        val currTimeStamp = clock.getCurrentTimeMs()
        if(state == CircuitBreakerState.CLOSED) {
            processRequestInClosedState(runnable, currTimeStamp)
        } else if(state == CircuitBreakerState.OPEN) {
            processRequestInHalfOpenState(runnable, currTimeStamp)
        } else if(state == CircuitBreakerState.HALF_OPEN) {
            processRequestInHalfOpenState(runnable, currTimeStamp)
        }
    }


    // HANDLING OF CLOSED STATE
    // The state machine is in closed state initially and can only transition into closed state
    // from HALF_OPEN state.
    private fun processRequestInClosedState(runnable: Runnable, currTimeStamp: Long) {
        try {
            relayService.relayRunnable(runnable)
        } catch (exp: Exception) {
            Logger.getLogger("").log(Level.WARNING, "Failure in execution", exp)
            processErrorInClosedState()
        }
    }

    private fun processErrorInClosedState() {
        val currTimeStamp = clock.getCurrentTimeMs()
        //currErrorCount++
        // No error time window that is already been tracked.
        if(errorTimeStart == -1L) {
            errorTimeStart = currTimeStamp
            currErrorCount = 0
        }

        // If the current time window has been over shot, we reset the window and error count.
        if(currTimeStamp - errorTimeStart >= config.timeWindow) {
            errorTimeStart = currTimeStamp
            currErrorCount = 0
        }

        currErrorCount++
        if(currErrorCount >= config.errorThreshold) {
            transitionToOpenState(currTimeStamp)
        }
    }

    // HANDLING OF OPEN state
    // Open state can be attained only from a CLOSED and HALF_OPEN state
    private fun processRequestInOpenState(runnable: Runnable, currTimeStamp: Long) {
        assert(circuitBrokenAt != -1L)
        // Throwing exception till we have gone beyond timeout.
        if(clock.getCurrentTimeMs() - circuitBrokenAt < config.timeout) {
            throw CircuitOpenException()
        } else {
            // Transitioning to half open.
            transitionToHalfOpenState(currTimeStamp)
            processRequestInHalfOpenState(runnable, currTimeStamp)
        }
    }


    // HANDLING OF HALF OPEN STATE
    // Half open state can only be transitioned into from OPEN state.
    private fun processRequestInHalfOpenState(runnable: Runnable, currTimeStamp: Long) {
        // Process request in half open state.
        try {
            relayService.relayRunnable(runnable)
            successInHalfOpen++
            // Checking if we can transition to open state.
            if(successInHalfOpen >= config.successThreshold) {
                transitionToClosedState()
            }
        } catch (exp: Exception) {
            Logger.getLogger("").log(Level.WARNING, "Failure in execution during HALF_OPEN state",
                exp)
            // We again have an error, so transition back to the open state.
            transitionToOpenState(currTimeStamp)
        }
    }

    // Defining state transitions.
    private fun transitionToOpenState(currTimeStamp: Long) {
        state = CircuitBreakerState.OPEN
        circuitBrokenAt = currTimeStamp // Storing the timestamp at which the circuit is broken in memory.
        errorTimeStart = -1L // Resetting the error time start.
        currErrorCount = 0
        successInHalfOpen = 0
    }

    private fun transitionToHalfOpenState(currTimeStamp: Long) {
        state = CircuitBreakerState.HALF_OPEN
        circuitBrokenAt = 0L
        errorTimeStart = -1L // Resetting the error time start.
        currErrorCount = 0
        successInHalfOpen = 0
    }

    private fun transitionToClosedState() {
        state = CircuitBreakerState.CLOSED
        // This is like a fresh state now so re-initialising to initial values.
        currErrorCount = 0
        errorTimeStart = -1L
        circuitBrokenAt = -1L
        successInHalfOpen = 0

    }



}