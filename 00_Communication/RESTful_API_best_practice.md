keywords: rest-api, 

---
### Guides
* Accept and respond with JSON
* Use nouns instead of verbs in endpoint paths
	- GET retrieves resources.
	- POST submits new data to the server.
	- PUT updates existing data.
	- DELETE removes data.
* Use hierarchy (logical nesting) on endpoints
* Handle errors gracefully and return standard error codes 
	- Common error HTTP status codes include:
			400 Bad Request – This means that client-side input fails validation.
			401 Unauthorized – This means the user isn’t not authorized to access a resource. It usually returns when the user isn’t authenticated.
			403 Forbidden – This means the user is authenticated, but it’s not allowed to access a resource.
			404 Not Found – This indicates that a resource is not found.
			500 Internal server error – This is a generic server error. It probably shouldn’t be thrown explicitly.
			502 Bad Gateway – This indicates an invalid response from an upstream server.
			503 Service Unavailable – This indicates that something unexpected happened on server side (It can be anything like server overload, some parts of the system failed, etc.).
* Allow filtering, sorting, and pagination
* Cache data to improve performance
* Versioning the APIs