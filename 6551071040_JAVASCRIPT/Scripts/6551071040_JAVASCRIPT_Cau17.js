function chuyenDoi() {
  let nhiPhan = document.getElementById("nhiphan").value.trim();
  if (/[^01]/.test(nhiPhan) || nhiPhan === "") {
    document.getElementById("ketqua").innerHTML =
      "Vui lòng nhập số nhị phân hợp lệ (chỉ gồm 0 và 1).";
    return;
  }
  let thapPhan = 0;
  let chieuDai = nhiPhan.length;
  for (let i = 0; i < chieuDai; i++) {
    let bit = Number(nhiPhan[i]);
    thapPhan += bit * Math.pow(2, chieuDai - i - 1);
  }
  document.getElementById("ketqua").innerHTML = 
    `${nhiPhan}<sub>(2)</sub> = ${thapPhan}<sub>(10)</sub>`;
}
