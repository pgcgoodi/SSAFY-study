const express = require("express");
const morgan = require("morgan");
const app = express();
const PORT = 8080;

app.use(express.json());
app.use(morgan("dev"));

const cors = require("cors");
app.use(cors());

const { pool } = require("./db");

app.get("/api/menus", async(req, res) => {
  try {
    const data = await pool.query("SELECT * FROM menus");
    if (data[0]) {
      return res.json(data[0]);
    }
  } catch(error) {
    console.log(error);
    return res.json({
      success: false,
      message: "전체 메뉴 목록 조회에 실패하였습니다."
    });
  }
})

app.get("/api/menus/:id", async(req, res) => {
  try {
    const data = await pool.query(
      `
      SELECT * FROM menus
      WHERE id=${req.params.id}
      `
    );
    if (data[0].length == 0) {
      return res.json({
        success: false,
        message: "해당 메뉴 목록 조회에 실패하였습니다."
      });
    }
    if (data[0][0]) {
      return res.json(data[0][0]);
    }
  } catch(error) {
    console.log(error);
    return res.json({
      success: false,
      message: "해당 메뉴 목록 조회에 실패하였습니다."
    });
  }
});

app.post("/api/menus", async(req, res) => {
  try {
    const data1 = await pool.query(
      `
      INSERT INTO menus
      (name, description, image_src)
      VALUES
      ("${req.body.name}", "${req.body.description}", "${req.body.image_src}")
      `
    );
    const data2 = await pool.query("SELECT * FROM menus");
    if (data1[0]) {
      return res.json(data2[0]);
    };

  } catch (error) {
    console.log(error);
    return res.json({
      success: false,
      message: "메뉴 등록에 실패하였습니다."
    });
  }
});

app.patch("/api/menus/:id", async(req, res) => {
  try {
    const data = await pool.query(
      `
      UPDATE menus
      SET name="${req.body.name}", description="${req.body.description}", image_src="${req.body.image_src}"
      WHERE id=${req.params.id}
      `
    );
    if (data[0]) {
      return res.json({
        success: true,
        message: "메뉴 정보 수정에 성공하였습니다."
      });
    }
  } catch (error) {
    console.log(error);
    return res.json({
      success: false,
      message: "메뉴 정보 수정에 실패하였습니다."
    });
  }
});

app.delete("/api/menus/:id", async(req, res) => {
  try {
    const data = await pool.query(
      `
      DELETE FROM menus WHERE id=${req.params.id}
      `
    );
    if (data[0]) {
      return res.json({
        success: true,
        message: "메뉴 삭제에 성공하였습니다."
      });
    }
  } catch (error) {
    console.log(error);
    return res.json({
      success: false,
      message: "메뉴 삭제에 실패하였습니다."
    });
  }
});

app.get("/api/orders", async(req, res) => {
  try {
    const data = await pool.query(
      `
      SELECT orders.id, name, quantity, request_detail
      FROM orders as orders
      INNER JOIN menus as menus
      ON orders.menus_id = menus.id
      `
    ); 
    if (data[0]) {
      return res.json(data[0]);
    }
  } catch(error) {
    console.log(error);
    return res.json({
      success: false,
      message: "전체 주문 목록 조회에 실패했습니다."
    })
  }
})

app.get("/api/orders/:id", async(req, res) => {
  try {
    const data = await pool.query(
      `
      SELECT * FROM orders
      WHERE id=${req.params.id}
      `
    );
    if (data[0].length == 0) {
      return res.json({
        success: false,
        message: "해당 주문 목록 조회에 실패했습니다."
      });
    }
    if (data[0][0]) {
      return res.json(data[0][0]);
    }
  } catch(error) {
    console.log(error);
    return res.json({
      success: false,
      message: "해당 주문 목록 조회에 실패했습니다."
    });
  }
});

app.post("/api/orders", async(req, res) => {
  try {
    const data = await pool.query(
      `
      INSERT INTO orders
      (quantity, request_detail, menus_id)
      VALUES
      ("${req.body.quantity}", "${req.body.request_detail}", "${req.body.menus_id}")
      `
    );
    const data2 = await pool.query("SELECT * FROM orders ORDER BY id DESC LIMIT 1")
    if (data[0]) {
      return res.json(data2[0][0]);
    }
  } catch (error) {
    console.log(error);
  }
});

app.patch("/api/orders/:id", async(req, res) => {
  try {
    const data = await pool.query(
      `
      UPDATE orders
      SET quantity="${req.body.quantity}", request_detail="${req.body.request_detail}", menus_id="${req.body.menus_id}"
      WHERE id=${req.params.id}
      `
    );
    if (data[0]) {
      return res.json({
        success: true,
        message: "주문 정보 수정에 성공하였습니다."
      });
    }
  } catch (error) {
    console.log(error);
    return res.json({
      success: false,
      message: "주문 정보 수정에 실패하였습니다."
    });
  }
});

app.delete("/api/orders/:id", async(req, res) => {
  try {
    const data = await pool.query(
      `
      DELETE FROM orders WHERE id=${req.params.id}
      `
    );
    if (data[0]) {
      return res.json({
        success: true,
        message: "주문 삭제에 성공하였습니다."
      });
    }
  } catch (error) {
    console.log(error);
    return res.json({
      success: false,
      message: "주문 삭제에 실패하였습니다."
    });
  }
});

app.listen(PORT, () => console.log(`this server is listening on ${PORT}`));
