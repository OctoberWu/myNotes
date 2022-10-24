keywords: nestjs

---
STEPS: 
1. 開一個新資料夾(workspace folder)
2. 確認nodejs 與 nestjs 的版本
若無： 安裝 cli tool
```sh
$npm i -g @nestjs/cli
```
3. 使用nest cli建立一個microservice
```sh
$nest new backend
$cd backend
```
Note: 若命名為 `myService` 會自動生成 `my-service`

4. 啟動服務測試
```sh
$npm run start 
# or
$npm run start:dev 
```
5. Controller/Service/Entity
* create
```sh 
$nest g module book 
$nest generate --flat controller book/controller/book 
$nest generate --flat service book/service/book 
$nest g --flat class book/book.entity 
```
* structure
```sh 
src
└───book
    ├───controller
    └───service
```
* Book Entity(book.entity)
```js
export class BookEntity {
  id: number;
  title: string;
}
```
* Book Service 
```js 
import { Injectable } from '@nestjs/common';
import { BookEntity } from '../book.entity';

@Injectable()
export class BookService {
  books: BookEntity[] = [
    <BookEntity>{ id: 1, title: 'NestJS 101' },
    <BookEntity>{ id: 2, title: 'Angular' },
  ];
  async getAll(): Promise<BookEntity[]> {
    return this.books;
  }
  async getById(id): Promise<BookEntity> {
    return this.books.find((_book: BookEntity) => _book.id === Number(id.id));
  }
}
```
* Book Controller
```js 
import { Controller, Get } from '@nestjs/common';
import { BookEntity } from '../book.entity';
import { BookService } from '../service/book.service';

@Controller('api/books')
export class BookController {
  constructor(private bookService: BookService) {}
  @Get()
  async getAll(): Promise<BookEntity[]> {
    return await this.bookService.getAll();
  }
  @Get(':id')
  async getById(@Param() id): Promise<BookEntity> {
    return await this.bookService.getById(id);
  }
}
```
