This LRU cache is for ad block data.
It, and the database, are currently setup so that the cache will be empty on startup. Whenever a video url is culled from a validated user, the server will check if the url ad timestamp data is in the cache and return the highest upvoted one. If it isn't, it will query the database for the ad timestamp information a, add it to the cache if it exists, and return it. 