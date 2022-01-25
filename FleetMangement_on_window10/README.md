# RFID.CSV
#### เป็นไฟล์เก็บข้อมูลตำแหน่ง X , Y ที่ถูกส่งมาจาก ROS(UBUNTU) -> SAMBA SERVER -> FLEET MANAGEMENT(WIN10) โดยได้มาจาก Ground truth state ซึ่งเป็น Plug-in ใน GAZEBO ซึ่งส่งค่าตำแหน่ง X,Y ชองหุ่นยนต์จริงที่อยู่บน Grid ของ GAZEBO ออกมา(ถ้า ODOMETRY จะส่งค่าที่วัดได้จาก Encoder ที่มาจากล้อซึ่งความจริงมันมี ERROR จากการหมุนของล้อนะ เค้าเลยใช้ Ground truth state) โดยไฟล์ที่เกี่ยวกับ RFID.CSV มีทั้งหมด 3 Files คือ rfid01.csv , rfid02.csv และ rfid03.csv </br>
# SENDGOAL0X.CSV
#### เป็นไฟล์เก็บข้อมูลตำแหน่ง X , Y ที่ถูกส่งมาจาก FLEET MANAGEMENT(WIN10) -> SAMBA SERVER -> ROS(UBUNTU) โดยได้มาจาก การคำนวณหาเส้นทางที่ใกล้ที่สุดของ Dijkstra Algorithm (ยังไม่สมบูรณ์) แล้วส่งค่าที่ต้องการให้หุ่นยนต์ไปยังตำแหน่งที่ต้องการ 
