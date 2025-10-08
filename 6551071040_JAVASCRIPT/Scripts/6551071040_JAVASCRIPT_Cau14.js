function taoSinhVien() {
  let name = document.getElementById("name").value.trim();
  let numberID = document.getElementById("numberID").value.trim();
  let gender = document.getElementById("gender").value;
  if (name === "" || numberID === "" || gender === "") {
    document.getElementById("ketqua").innerHTML =
      "Vui lòng nhập đầy đủ thông tin sinh viên.";
    return;
  }
  const Student = {
    Name: name,
    NumberID: numberID,
    Gender: gender
  };
  document.getElementById("ketqua").innerHTML = `
     <b>Thông tin sinh viên:</b><br>
     Họ và tên: ${Student.Name}<br>
     Mã số sinh viên: ${Student.NumberID}<br>
     Giới tính: ${Student.Gender}
  `;
}
