package com.trackmyfamily

interface RateLimiter {

    fun isAllowed(clientId: String): Boolean

}