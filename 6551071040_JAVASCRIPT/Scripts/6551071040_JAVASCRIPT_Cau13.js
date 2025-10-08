function laSoNguyenTo(x) {
  if (x < 2) return false; 
  for (let i = 2; i <= Math.sqrt(x); i++) {
    if (x % i === 0) return false; 
  }
  return true;
}
function lietKe() {
  let nStr = document.getElementById("n").value.trim();
  let n = Number(nStr);
  if (isNaN(n) || !Number.isInteger(n) || n <= 1) {
    document.getElementById("ketqua").innerHTML =
      "Vui lòng nhập n là số nguyên dương lớn hơn 1.";
    return;
  }
  let soNguyenTo = [];
  for (let i = 2; i < n; i++) {
    if (laSoNguyenTo(i)) soNguyenTo.push(i);
  }
  if (soNguyenTo.length === 0) {
    document.getElementById("ketqua").innerHTML = 
      `Không có số nguyên tố nào nhỏ hơn ${n}.`;
  } else {
    document.getElementById("ketqua").innerHTML = 
      `Các số nguyên tố nhỏ hơn ${n} là: ${soNguyenTo.join(", ")}`;
  }
}
