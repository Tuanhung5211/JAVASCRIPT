function daoNguoc() {
  let soNhap = document.getElementById("soNhap").value.trim();
  // Kiểm tra nếu không nhập gì
  if (soNhap === "") {
    document.getElementById("ketqua").innerHTML = "Vui lòng nhập một số.";
    return;
  }
  // Kiểm tra số nguyên
  if (isNaN(soNhap) || !Number.isInteger(Number(soNhap))) {
    document.getElementById("ketqua").innerHTML = "Vui lòng nhập số nguyên hợp lệ.";
    return;
  }
  // Đảo số
  let dao = soNhap.split("").reverse().join("");
  // Giữ cho số âm (nếu có)
  if (dao.endsWith("-")) {
    dao = "-" + dao.slice(0, -1);
  }
  // Xuất kết quả
  document.getElementById("ketqua").innerHTML = `Kết quả đảo: ${dao}`;
}
