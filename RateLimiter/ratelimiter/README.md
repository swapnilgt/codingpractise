## Overview
In this module, we are aiming at implementing different rate limiting algorithms. We want to create unified interface for them and create specific implementations for each algorithm. We also want to create a fun UI simulation for each of the algorithms.

## Rate Limiting Algorithms
1. **Token Bucket**: In this algorithm, tokens are added to a bucket at a fixed rate. Each request requires a token to be processed, and if there are no tokens available, the request is denied. If there is sudden burst of traffic coming in, the bucket can handle it as long as there are enough tokens. Any extra requests will be denied. Following are the parameters for this algorithm:
   - `bucket_size`: Maximum number of tokens in the bucket.
   - `refill_rate`: Number of tokens added to the bucket per second.

This algorithm can lead to burst of traffic at the end of the time window. Suppose, we have a capacity of 10 tokens and a refill rate of 1 token per second. If there are no requests for 10 seconds, the bucket will be full with 10 tokens. If suddenly 15 requests come in at once, the first 10 requests will be allowed and the remaining 5 will be denied. Post the 5th second, the bucket will start refilling at the rate of 1 token per second. We might not call it a burst, but it can lead to sudden spike in traffic. Further, smoothening can be done by reducing the bucket size and increasing the refill rate. Essentially, this algorithm helps in smoothing out the traffic over a period of time.

2. **Leaky Bucket**: In this algorithm, requests are added to a queue(bucket) and processes at a fixed rate. This is different from the token-bucket algorithm in where the control point is being put. In token-bucket, the control point is at producer level. In leaky-bucket, the control point is at the consumer level. The queue has a fixed capacity and if the queue is fill, any new incoming requests with be denied. Following are the parameters for this algorithm:
   - `bucket_size`: Maximum number of requests in the bucket.
   - `leak_rate`: Number of requests processed from the bucket per second.

This algorithm will always ensure smoothening of traffic. Suppose, we have a capacity of 10 requests and a leak rate of 1 request per second. If there are no requests for 10 seconds, the bucket will be empty. If suddenly 15 requests come in at once, the first 10 requests will be added to the bucket and the remaining 5 will be denied. Post the 5th second, the bucket will start leaking at the rate of 1 request per second. This will ensure that the traffic is smoothed out over a period of time. With this algorithm, we can ensure that the servers are not overwhelmed with sudden burst of traffic and don't go beyond their capacity.

3. **Fixed Window**: In this algorithm, we define a fixed time window and allow a certain number of requests in that window. Any requests beyond that limit is denied. Following are the parameters for this algorithm:
   - `window_size`: Size of the time window in seconds.
   - `max_requests`: Maximum number of requests allowed in the time window.

This algorithm can lead to burst of traffic at the edge of the time windows. Suppose the time window is 1 minute and maximum number of requests allowed is 10. If 10 requests come in the first 59 seconds, they will be allowed. If suddenly 10 more requests come in the next second, they will also be allowed as they fall in the next time window. This will lead to 20 requests being processed within actual time of 1 minute.

4. **Sliding Window Log**: In this algorithm, we define a time window that slides over time. We keep track of the number of requests in the current window and allow or deny requests based on that. Following are the parameters for this algorithm:
   - `window_size`: Size of the time window in seconds.
   - `max_requests`: Maximum number of requests allowed in the time window.
This algorithm helps in solving the traffic burst problem posed by the fixed window algorithm. Helps in smoothing the traffic over a period of time as it ensures only a maximum number of requests are allowed in a given time window.

5. **Sliding Window Counter**: This algorithm is a more efficient version of the sliding window log algorithm. Instead of keeping track of each request, we keep track of the number of requests in each window. Instead of maintaining log of each and every request in the past, this algorithm relies on the a weighted average of the percentage of number of requests in the previous window and uses that to calculate the available quota in the current window. Following are the parameters for this algorithm:
   - `window_size`: Size of the time window in seconds.
   - `max_requests`: Maximum number of requests allowed in the time window.