function tinhGiaiThua() {
  let nStr = document.getElementById("n").value.trim();
  let n = Number(nStr);
  if (!Number.isInteger(n) || n < 0) {
    document.getElementById("ketqua").innerHTML =
      "Vui lòng nhập n là số nguyên dương (n ≥ 0).";
    return;
  }
  let giaiThua = 1;
  for (let i = 1; i <= n; i++) {
    giaiThua *= i;
  }
  document.getElementById("ketqua").innerHTML =
    `Kết quả: ${n}! = ${giaiThua.toLocaleString()}`;
}
