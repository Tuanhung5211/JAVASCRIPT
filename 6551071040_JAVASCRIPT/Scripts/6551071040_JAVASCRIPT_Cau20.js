function hienThiNgayGio() {
  let now = new Date();

  let ngay = now.getDate();
  let thang = now.getMonth() + 1; 
  let nam = now.getFullYear();

  let gio = now.getHours();
  let phut = now.getMinutes();
  let giay = now.getSeconds();
  let ngayGioStr = `Hiện tại là: ${ngay}/${thang}/${nam} ${gio}:${phut}:${giay}`;
  alert(ngayGioStr);
}
