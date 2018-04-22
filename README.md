### "Vacuum-Cleaner-Amazing"<br>
---
# Introduction<br>
   ผู้คนในยุคปัจจุบันไม่ค่อยมีเวลาจากเหตุผลต่างๆ จึงทำให้บ้านสกปรกมีฝุ่นที่ต้องทำความสะอาด จึงได้จัดทำ โปรเจค“เครื่องดูดฝุ่นสุดมหัศจรรย์” ทำเกี่ยวกับหุ่นยนต์เครื่องดูดฝุ่นอัตโนมัติ(Auto Robot Cleaner) ที่จะคอยดูดฝุ่นหรือเศษผงต่างๆตามพื้น และเคลื่อนที่โดยอัตโนมัติโดยมีการใช้เซ็นเซอร์(Sensor) ในการหลบสิ่งกีดขวางโดยใช้ Hardware ที่ใช้คือ อาดูโน่(Arduino)  และ Software ใช้ภาษา C, C++ ในการเขียนโปรแกรม ส่วนตัวดูดฝุ่นนั้นทำมาจากอุปกรณ์ดัดแปลงอุปกรณ์เหลือใช้มาประกอบกับตัวอาดูโน่<br>
# ![](/img/help.png) How to use<br>
1. ให้ทำการดาวน์โหลดแอพ Blynk ในโทรศัพท์มือถือ และ login เพื่อเริ่มต้นใช่งานแอพพิเคชั่น  
2. หลังการดาวน์โหลด กด New Project ตามรูปด่านล่าง  
 ![](/img/new_projectBlynk.png)<br>
3. ทำการเพิ่มปุ่มกด Button และตั้งค่า PIN เป็น Virtual ตามรูป
| ![Image](/img/UI_blynk.png)| ![Image](/img/v1.jpg) | ![Image](/img/v2.jpg) | ![Image](/img/v3.jpg) | ![Image](/img/v4.jpg) | ![Image](/img/v5.jpg) |<br>
4. ทำการลงซอฟแวร์ที่ชื่อ Blynk_MCU ในโฟลเดอร์ Main Project CP60 ให้แก่ตัว Node_MCU และทำการแก้ไข Wifi_id , Wifi_passwords , auth(สามารถเข้าไปดูได้ที่ e-mail ที่สมัคร Blynk) ให้ตรงกับ Wifi ของท่าน  
 ![](/img/ip_user.png)<br>
 5. ทำการลงซอฟแวร์ที่ชื่อ vacuum ในในโฟลเดอร์ Main Project CP60 ให้แก่ตัว Aduino  
---
# ![](/img/tools.png) Tools  
* Arduino Uno R3 x1  
* NODE MCU V3    x1  
* Breadboard x1  
* Servo x1  
* Rocker Switch x1
* Ultrasonic HC-SR04 x1  
* Smart car motor + wheels x2  
* Motor Drive Module (L298N) x1  
* รางถ่านไฟ 4 ก้อน x1 
* ถ่านไฟ 6v x4
* สายไฟจัมเปอร์  
---
# DOWNLOAD<br>
![](/img/notebook.png) Installation Requirements Library<br>
 * [Arduino](https://www.arduino.cc/en/Main/Software)<br>
 * [Ultrasonic](https://github.com/ErickSimoes/Ultrasonic)  <br>
 * [AF_motor](https://github.com/adafruit/Adafruit-Motor-Shield-library) Credit by tdicola <br>
 * [MCU]() <br>
 * [Blynk](https://github.com/blynkkk/blynk-library)  
 
### ADD ESP8266  
1. open arduino.io  
2. File -> Preference -> add this url: http://arduino.esp8266.com/stable/package_esp8266com_index.json   
to Additional Boards Manager URLs -> ok  
3. Tools -> Board -> Boards Manager
Type esp8266 in search -> install  

### Install Library  
 * Sketch -> Include library -> Add.Zip Library...  
 * Select all Zip file  
---
# ![](/img/Supervisor.png) Assistant Teacher<br>

| ผศ. ดร. กิติ์สุชาติ พสุภา	| ผศ. ดร. ปานวิทย์ ธุวะนุติ  |
| :-------------: |:-------------:|
| ![Image](https://github.com/sagelga/ComPro_Project/blob/master/Resource/Aj.%20Oong.png)      | ![Image](https://github.com/sagelga/ComPro_Project/blob/master/Resource/Aj.%20Panwit.png) | $1600 |<br>

รายงานนี้เป็นส่วนหนึ่งของวิชา Computer Programming (รหัส 06016315)<br>
คณะเทคโนโลยีสารสนเทศ สถาบันเทคโนโลยีพระจอมเกล้าเจ้าคุณทหารลาดกระบัง
---
# ![](/img/member.png) Team Members
|  |ชื่อ|นามสกุล|GitHub Username|รหัสนักศึกษา|
|:-:|--|------|---------------|---------|
|![](/img/oven.jpg)| สุธี | พิละมาตย์ | [@kpez](https://github.com/kpez) | 60070105 |
|![](/img/pack.jpg)| อภิชาติ | ชัยณรงค์ฤทธิ์ | [@apichart](https://github.com/apichart2425) | 60070111 |
|![](/img/patty.jpg)| อภิษิญา | เงินแย้ม | [@apisiya](https://github.com/Apisiya) | 60070113 |
---
Faculty of Information Technology<br>
King Mongkut's Institute of Technology Ladkrabang
