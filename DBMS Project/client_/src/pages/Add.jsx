import React from 'react'
import { useState } from 'react'
import axios from "axios"
const Add = () => {
const [book,setBook] = useState({
  title:"",
  desc:"",
  price:null,
  cover:"",
});

const navigate = useNavigate()

const handleChange = (e) =>{
  setBook(prev=>({...prev, [e.target.  name]: e.target.value}));
};

  const handleClick = async e =>{
    e.preventDefault()
    try{
      await axios.post("http://localhost:3000/books",book)
      navigate("/")
    }catch(err){
      console.log(err)
    }
  }

  console.log(book)
  return (
    <div classname='form'>
      <h1>Add New Book</h1>
      <input type="text" placeholder='title' onChange={handleChange} name="title"/>
      <input type="text" placeholder='desc' onChange={handleChange} name="desc"/>
      <input type="number" placeholder='price' onChange={handleChange} name="price"/>
      <input type="text" placeholder='cover' onChange={handleChange} name="cover"/>
      <button onClick={handleClick}></button>
    </div>
  );
};

export default Add