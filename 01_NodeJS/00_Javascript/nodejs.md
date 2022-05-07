### Issue
```sh
npm ERR! Unexpected end of JSON input while parsing near '...t.1","jest-runner":"^'
```

### Solution
```sh
$npm cache clean --force
```