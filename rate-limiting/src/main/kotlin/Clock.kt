package com.trackmyfamily

interface Clock {
    /**
     * Get the current time from epoch in milliseconds.
     */
    fun getCurrentTimeMs(): Long
}