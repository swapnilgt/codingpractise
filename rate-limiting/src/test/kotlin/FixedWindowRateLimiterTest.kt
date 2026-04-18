import com.trackmyfamily.FixedWindowRateLimiter
import com.trackmyfamily.RateLimiter
import org.junit.jupiter.api.AfterEach
import org.junit.jupiter.api.BeforeEach

import org.junit.jupiter.api.Assertions.*
import org.junit.jupiter.api.Test

class FixedWindowRateLimiterTest {

    private lateinit var SUT: RateLimiter
    private val clock = DummyClock()

    @BeforeEach
    fun setUp() {
        SUT = FixedWindowRateLimiter(
            500,
            5,
            clock
        )
    }

    @Test
    fun `when a client request reaches for the first time, it is allowed`() {

        clock.currTime = 1000L

        assertEquals(true, SUT.isAllowed("client1"))
    }

    @Test
    fun `when a there is a request reaching within the time window and we still have buffer not full, request is allowed`() {

        // Setting up
        clock.currTime = 1000L
        SUT.isAllowed("client1")

        // Moving time ahead.
        clock.currTime = 1300L

        // Testing
        assertEquals(true, SUT.isAllowed("client1"))

        // Moving further ahead in time.
        clock.currTime = 1499L
        // Testing
        assertEquals(true, SUT.isAllowed("client1"))
    }


    @Test
    fun `when we hit the last request within a time window it is accepted`() {

        // Setting up
        clock.currTime = 1000L
        SUT.isAllowed("client1")
        // Setting up
        clock.currTime = 1001L
        SUT.isAllowed("client1")

        // Setting up
        clock.currTime = 1002L
        SUT.isAllowed("client1")

        // Setting up
        clock.currTime = 1003L
        SUT.isAllowed("client1")


        // Moving time ahead.
        clock.currTime = 1300L

        // Testing
        assertEquals(true, SUT.isAllowed("client1"))
    }

    @Test
    fun `when we go beyond the buffer size within the time window, request is rejected`() {

        // Setting up
        clock.currTime = 1000L
        SUT.isAllowed("client1")
        // Setting up
        clock.currTime = 1001L
        SUT.isAllowed("client1")

        // Setting up
        clock.currTime = 1002L
        SUT.isAllowed("client1")

        // Setting up
        clock.currTime = 1003L
        SUT.isAllowed("client1")


        // Moving time ahead.
        clock.currTime = 1300L
        SUT.isAllowed("client1")

        // Testing
        assertEquals(false, SUT.isAllowed("client1"))
    }

    @Test
    fun `when a there is a request reaching within the at the edge of time window, it is accepted`() {

        // Setting up
        clock.currTime = 1000L
        SUT.isAllowed("client1")

        // Moving time ahead.
        clock.currTime = 1500L

        // Testing
        assertEquals(true, SUT.isAllowed("client1"))
    }

    @Test
    fun `when a there is a request reaching outside the current time window, it is accepted`() {

        // Setting up
        clock.currTime = 1000L
        SUT.isAllowed("client1")

        // Moving time ahead.
        clock.currTime = 30000L

        // Testing
        assertEquals(true, SUT.isAllowed("client1"))
    }

    @Test
    fun `when a new time window is reset, we again start accepting new requests till the buffer`() {

        // Setting up
        clock.currTime = 1000L
        SUT.isAllowed("client1")

        // Setting up 1
        clock.currTime = 1500L
        assertEquals(true, SUT.isAllowed("client1"))

        // Setting up 2
        clock.currTime = 1501L
        assertEquals(true, SUT.isAllowed("client1"))

        // Setting up 3
        assertEquals(true, SUT.isAllowed("client1"))

        // Setting up 4
        assertEquals(true, SUT.isAllowed("client1"))

        // Setting up 5
        assertEquals(true, SUT.isAllowed("client1"))

        // Testing
        assertEquals(false, SUT.isAllowed("client1"))

    }



    @AfterEach
    fun tearDown() {
    }
}