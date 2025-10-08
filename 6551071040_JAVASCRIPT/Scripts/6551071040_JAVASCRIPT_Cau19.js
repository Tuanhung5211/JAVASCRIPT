function tinhLaiSuat() {
  let P = Number(document.getElementById("principal").value.trim());
  let r = Number(document.getElementById("rate").value.trim());
  let n = Number(document.getElementById("years").value.trim());
  if (isNaN(P) || P <= 0 || isNaN(r) || r < 0 || !Number.isInteger(n) || n <= 0) {
    document.getElementById("ketqua").innerHTML =
      "Vui lòng nhập đúng dữ liệu: số tiền > 0, lãi suất ≥ 0, số năm nguyên dương.";
    return;
  }
  let A = P * (1 + (r / 100) * n);
  A = Math.round(A * 100) / 100;
  document.getElementById("ketqua").innerHTML =
    `Sau ${n} năm, tổng số tiền là: ${A.toLocaleString()} VND`;
}
