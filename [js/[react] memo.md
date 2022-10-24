keywords: vs_code_plugins



---
### rundown
1. install nodejs
2. install npm
3. install VSCode 
---


### 5. 2022.10.24
1. ES7+ React/Redux/React-Native snippets (v4.4.3)
2. html to JSX (v0.0.1)

6. create new react app
```sh
$npm install -g create-react-app
$create-react-app admin-app-demo
$npm install admin-lte --save
```

7. copy dist and pugin folders to public
> replace url with `%PUBLIC_URL%` by prefix


8. copy components(`Header`, `Menu`, `Dashboard`,`Footer`) to `/src` folder


---
### foot-note:
1. multiple pages - use react router
* add react router
```sh 
npm install react-router-dem
```

2. version update
#### Upgrade all <Switch> elements to <Routes>
* updatation for react-router-dom v6
```js
// This is a React Router v5 app
import {
  BrowserRouter,
  Switch,
//^^^^^^
  Route,
  Link,
  useRouteMatch,
} from "react-router-dom";

function App() {
  return (
    <BrowserRouter>
      <Switch>
        <Route exact path="/">
          <Home />
        </Route>
        <Route exact path="/" component={Home}/>
        <Route path="/users">
          <Users />
        </Route>
      </Switch>
    </BrowserRouter>
  );
}


// This is a React Router v6 app
import {
  BrowserRouter,
  Routes,
//^^^^^^
  Route,
  Link,
} from "react-router-dom";

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Home />} />
				              //^^^^^^^
        <Route path="users/*" element={<Users />} />
      </Routes>
    </BrowserRouter>
  );
}
```