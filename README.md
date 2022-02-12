# การติดตั้งและทดลองโปรแกรม
## เกี่ยวกับ SAMBER SERVER 
1.ติดตั้ง Samba server เครื่อง ubuntu เพื่อใช้ในการ**รับ-ส่ง**ข้อมูลพิกัดที่หุ่นยนต์เคลื่อนที่ >> https://youtu.be/SPTLuuAJhG0 <br />
2.Check ip เครื่อง ubuntu โดยใช้คำสั่ง **$ ifconfig** ไปดูตรง inet-addr ว่าเป็นเลขอะไร เช่น 192.168.5.34 <br />
3.จากนั้นเปิด เครื่อง Windows10 แล้วเปฺิดโปรแกรม Run -> ช่อง Open: ให้พิมพ์ \\\เลข ip เครื่อง ubuntu เช่น \\\192.168.5.34 จากนั้นกด OK จะมี Folder Server ขึ้นมา ส่วนวิธีเปิด Folder Server บน ubuntu ไปดูที่ >> https://youtu.be/62qekDezU6Q เพราะมันซ่อนอยู่ตรง /home Folder
## 
## เกี่ยวกับ โปรแกรม Fleet management บน Windows10 (รอเพชรมาเขียน)
1.Download ไฟล์ที่ชื่อว่า FleetMangement_on_window10
##
## เกี่ยวกับ โปรแกรมที่ควบคุมหุ่นยนต์และไฟล์ Environment ของ GAZEBO (ubuntu)
1.Download ไฟล์ Standard_Turtlebot3 ซึ่งเป็นไฟล์เก็บ urdf หุ่นยนต์และ Envoronment จำลอง และต้อง Download package "Standard_Turtlebot3" ที่นี่ >> https://github.com/ROBOTIS-GIT/turtlebot3_simulations ไปใส่ใน catkin_ws/src <br />
2.Download ไฟล์ odom_subscriber ไปใส่ใน catkin_ws/src  ซึ่ง odom_subscriber เป็น  Package เก็บ log file และ Ground truth state ซึ่งใช้ในการบอกตำแหน่งบนพื้นของหุ่นยนต์ใน Software GAZEBO <br />
3.Download ไฟล์ send_goal_robot01 , send_goal_robot02 และ send_goal_robot03 ไปใส่ใน catkin_ws/src ซึ่งทั้ง 3 package นี้ใช้สำหรับควบคุมหุ่นยนต์ในโปรแกรม GAZEBO <br />
4.ลืมอัพโหลดไฟล์ map ที่ scan มาแล้ว อย่าลืมเตือนนะ <br />
5.อย่าลืม build catkin workspace โดยใช้คำสั่ง **$ cd ~/catkin_ws** -> **$ catkin_make**
##
## เกี่ยวกับ Read and Write .csv File คลิ๊กเบย
https://github.com/KomKGT/ReadAndWrite_CSVFile
##
