keywords: nodejs, typescript, express, restful, postgresql, redis, pm2, typeorm, node-best-practices

---
### Production ready Node.js REST API Setup using TypeScript, PostgreSQL and Redis

#### tech stack:
1. **TypeScript.** - with a strict mode. All types have to be explicitly specified.
2. **Express.** - The last version fully supports async/await, so no callback and no explicit promises in our routes/controllers.
3. **PostgreSQL.** This time a relational database. Let’s see how easy it’s to use.
4. **TypeORM** — powerful ORM written in TypeScript, supports migrations, Active Record, has an excellent query builder and much more.
5. **Winston** — A logger for just about everything :)
6. **Redis.** We will use this in-memory store for caching. It’s going to one extra line of code which makes a huge difference in performance.
7. **PM2.** — process manager for node.js apps, it includes clustering, load balancing, simple terminal monitoring, and log management.


### references:
  * [Production ready Node.js REST API Setup using TypeScript, PostgreSQL and Redis](https://itnext.io/production-ready-node-js-rest-apis-setup-using-typescript-postgresql-and-redis-a9525871407)
  * [alexpermiakov/node-rest-api](https://github.com/alexpermiakov/node-rest-api/)
	* [Node.js Best Practices](https://github.com/goldbergyoni/nodebestpractices#2-error-handling-practices)