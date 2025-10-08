function tinhMu() {
  let bStr = document.getElementById("b").value.trim();
  let nStr = document.getElementById("n").value.trim();
  let b = Number(bStr);
  let n = Number(nStr);
  if (
    isNaN(b) || isNaN(n) ||
    !Number.isInteger(b) ||
    !Number.isInteger(n) ||
    b <= 0 || n < 0
  ) {
    document.getElementById("ketqua").innerHTML =
      "Vui lòng nhập b và n là số nguyên dương (b > 0, n ≥ 0).";
    return;
  }
  let ketQua = Math.pow(b, n);
  document.getElementById("ketqua").innerHTML =
    `Kết quả: ${b}<sup>${n}</sup> = ${ketQua}`;
}
