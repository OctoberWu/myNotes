### Error Handling Guideline in RESTful APIs

* Error response template:
```json
{
  "status": 400,
  "reason": "Bad Request",
  "errors": [
      {"type": "map", "message": "The data is format is invalid"},
      {"type": "rmt", "message": "RMT is down"}
  ]
}
```


References:
- [RESTful API Design: How to handle errors](https://alidg.me/blog/2016/9/24/rest-api-error-handling)
- [List of HTTP status codes](https://en.wikipedia.org/wiki/List_of_HTTP_status_codes)
- [HTTP status codes used by world-famous APIs](https://gist.github.com/vkostyukov/32c84c0c01789425c29a)
- [Choosing an HTTP Status Code — Stop Making It Hard](https://www.codetinkerer.com/2015/12/04/choosing-an-http-status-code.html)
- [REST API error return good practices [closed]](https://stackoverflow.com/questions/942951/rest-api-error-return-good-practices)

Read More:
* Enterprise Integration Patterns: Designing, Building, and Deploying Messaging Solutions
* The REST API Design Handbook