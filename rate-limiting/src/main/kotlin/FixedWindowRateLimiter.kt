package com.trackmyfamily

import java.util.concurrent.ConcurrentHashMap
import java.util.function.BiFunction

class FixedWindowRateLimiter(
    private val timeWindowMs: Long,
    private val maxNumRequests: Int,
    private val clock: Clock
): RateLimiter {

    // Map storing the clientId as key and the window start time as the value.
    private val clientInitTimeMap = ConcurrentHashMap<String, Long>()
    private val clientNumRequestMap = ConcurrentHashMap<String, Int>()

    override fun isAllowed(clientId: String): Boolean {

        if(!clientInitTimeMap.containsKey(clientId)) {
            clientInitTimeMap[clientId] = clock.getCurrentTimeMs()
            clientNumRequestMap[clientId] = 1
            return true
        } else {
            // Need to take care of concurrency handling.
            if(clock.getCurrentTimeMs() - clientInitTimeMap[clientId]!! < timeWindowMs
                && clientNumRequestMap[clientId]!! < maxNumRequests ) {
                clientNumRequestMap.compute(clientId) { _, value -> value?.plus(1) }
                return true
            } else if(clock.getCurrentTimeMs() - clientInitTimeMap[clientId]!! >= timeWindowMs) {
                clientInitTimeMap[clientId] = clock.getCurrentTimeMs()
                clientNumRequestMap[clientId] = 1
                return true
            }
        }

        return false
    }
}