function tinhToanHinhTru() {
  // a)
  let HinhTru = { radius: 10, height: 15 };
  let theTich = Math.PI * Math.pow(HinhTru.radius, 2) * HinhTru.height;
  let output = `Bán kính (r): ${HinhTru.radius}<br>
Chiều cao (h): ${HinhTru.height}<br>
Thể tích hình trụ: V = π × r² × h = ${theTich.toFixed(2)}<br><br>`;
  // b)
  HinhTru.height = 30;
  let dienTich = 2 * Math.PI * HinhTru.radius * (HinhTru.height + HinhTru.radius);
  output += `Sau khi cập nhật:<br>
Chiều cao mới (h): ${HinhTru.height}<br>
Diện tích toàn phần: S = 2πr(h + r) = ${dienTich.toFixed(2)}`;
  document.getElementById("ketqua").innerHTML = output;
}
