Note:
1. Good error handling can make debugging easier.
2. Speak the same language and has the same expectation
3. Implement it and ensure consistency across application

* Good API errors differentiate client and server errors

2xx : Success
4xx : Client Errors
5xx : Server Errors

200 OK (A GET or POST request was successful)
201 Created (Confirms that a request has been fulfilled and a new resource has been created for the client)
202 Accepted (The requests has been accepted, and that processing has begun)
400 Bad Request (Client sent an invalid request, such as lacking required request body or parameter)
401 Unauthorized (Client failed to authenticated with server)
403 Forbidden (Client authenticated but does not have permission to access the requested resource)
404 Not Found (The requested resource does not exist)
500 Internal Server Error (a generic error occurred on the server)
503 Service Unavailable (The requested service is not available)