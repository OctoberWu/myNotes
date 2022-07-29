keywords: fox glove,

---

Getting started:
1. clone repo
2. run `yarn install`
3. launch the development environment

```shell
yarn install

# To launch the desktop app (run both scripts concurrently):
$ yarn desktop:serve        # start webpack
$ yarn desktop:start        # launch electron

# To launch the browser app:
$ yarn web:serve

# To launch the browser app using a local instance of the backend server:
$ yarn web:serve:local

# To launch the storybook:
$ yarn storybook

# Advanced usage: running webpack and electron on different computers (or VMs) on the same network
$ yarn desktop:serve --host 192.168.xxx.yyy         # the address where electron can reach the webpack dev server
$ yarn dlx electron@13.0.0-beta.13 .webpack # launch the version of electron for the current computer's platform

# To launch the desktop app using production API endpoints
$ yarn desktop:serve --env FOXGLOVE_BACKEND=production
$ yarn desktop:start

# NOTE: yarn web:serve does not support connecting to the production endpoints
```

#### Other useful commands:
```shell
$ yarn run          # list available commands
$ yarn lint         # lint all files
$ yarn test         # run all tests
$ yarn test:watch   # run tests on changed files
```