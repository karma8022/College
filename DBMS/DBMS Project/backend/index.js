import express, { json } from "express"
import mysql from "mysql"
import cors from "cors"
const app = express()


const db = mysql.createConnection({
    host:"localhost",
    user:"root",
    password:"neeraj@123",
    database:"test"
})

app.use(express.json())
app.use(cors())

app.get("/",(req,res)=>{
    res.json("Hello this is the backend")
})

app.get("/books",(req,res)=>{
    const q = "SELECT * FROM books"
    db.query(q,(err,data)=>{
        if(err) return res.json(err)
        return res.json(data) 
    })
})

app.post("/books",(req,res)=>{
  const q ="INSERT INTO books (`title`,`desc`,`cover`,`price`) VALUES (?)"
  const values = [
    req.body.title,
    req.body.desc, 
    req.body.cover,
    req.body.price,
  ];
  db.query(q, [values],(err,data)=>{
    if(err) return res.json(err);
    return res.json("Book has been created successfully");
 });
})

app.delete("/books/:id",(req,res)=>{
    const bookID = req.params.id;
    const q ="DELETE FROM books WHERE id = ?"
    db.query(q,[bookID],(err,data)=>{
        if (err) return res.json(err);
        return res.json("Book has been deleted successfully")
    })
})

app.put("/books/:id",(req,res)=>{
    const bookID = req.params.id;
    const q ="UPDATE books SET `title`=?,`desc`=?,`price`=?,`cover`=? WHERE id =?";
    const values = [
        req.body.title,
        req.body.desc,
        req.body.price, 
        req.body.cover,
    ];
    db.query(q, [...values,bookID],(err,data)=>{
      if(err) return res.json(err);
      return res.json("Book has been updated successfully");
   });
  })





app.listen(8800,()=>{
    console.log("Connected to backend!")
})

app.post("/books",(req,res)=>{
    const q ="INSERT INTO books (`id`, `title`,`desc`,`cover`,`price`) VALUES (?, ?, ?, ?, ?)"
    const values = [
      req.body.id,
      req.body.title,
      req.body.desc, 
      req.body.cover,
      req.body.price,
    ];
    db.query(`SELECT id FROM books WHERE id=${req.body.id}`, (error, result) => {
      if (error) return res.json(error);
      if (result.length > 0) {
        return res.status(409).json({ message: 'ID already exists' });
      } else {
        db.query(q, values, (err, data) => {
          if(err) return res.json(err);
          return res.json("Book has been created successfully");
        });
      }
    });
  })
  