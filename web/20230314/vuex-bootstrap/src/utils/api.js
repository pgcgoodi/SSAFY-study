import axios from "axios";

const request = axios.create({
  baseURL: "https://jsonplaceholder.typicode.com"
});

export const api = {
  jsonplaceholder:{
    findAll:() => request.get("/todos"),
  }
};