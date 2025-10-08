function thaoTacUser() {
  let User = { Name: "Max", Age: 20 };
  // a)
  let output = `Thông tin ban đầu:<br>
  Tên: ${User.Name}<br>
  Tuổi: ${User.Age}<br><br>`;
  // b)
  User.Surname = "Lee";
  User.Age = 30;
  output += `Sau khi cập nhật:<br>
  Họ: ${User.Surname}<br>
  Tên: ${User.Name}<br>
  Tuổi: ${User.Age}`;
  document.getElementById("ketqua").innerHTML = output;
}
