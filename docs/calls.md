
## Basic
```

CREATE users
DROP users

INSERT Tymoti INTO users

GET Tymoti FROM users
GET Tymoti.id FROM users
GET ALL FROM users

DELETE Tymoti FROM users

## Modification

```

SET Tymoti.id 54153 FROM users
SET Tymoti.name "Tymoti" FROM users
SET Tymoti.age 17 FROM users

UNSET Tymoti.age FROM users

## Searching

```
FIND FROM users WHERE id=54153
FIND FROM users WHERE age>18
FIND FROM users WHERE name="Tymoti"

GET ALL FROM users WHERE age>18
```

###### Operators:
```
=
!=
>
<
>=
<=
```

## Logic

```
GET ALL FROM users WHERE age>18 AND admin=true

GET ALL FROM users WHERE age<18 OR admin=true
```

## Sorting / limit

```
GET ALL FROM users SORT id ASC

GET ALL FROM users SORT id DESC

GET ALL FROM users LIMIT 10

GET ALL FROM users WHERE age>18 SORT age DESC LIMIT 20
```

## Tables / Information

```
LIST TABLES
DESCRIBE users
COUNT users
EXISTS users
```