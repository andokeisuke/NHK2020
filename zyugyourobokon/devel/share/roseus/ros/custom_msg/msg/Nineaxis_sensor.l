;; Auto-generated. Do not edit!


(when (boundp 'custom_msg::Nineaxis_sensor)
  (if (not (find-package "CUSTOM_MSG"))
    (make-package "CUSTOM_MSG"))
  (shadow 'Nineaxis_sensor (find-package "CUSTOM_MSG")))
(unless (find-package "CUSTOM_MSG::NINEAXIS_SENSOR")
  (make-package "CUSTOM_MSG::NINEAXIS_SENSOR"))

(in-package "ROS")
;;//! \htmlinclude Nineaxis_sensor.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass custom_msg::Nineaxis_sensor
  :super ros::object
  :slots (_accl _gyro _mag ))

(defmethod custom_msg::Nineaxis_sensor
  (:init
   (&key
    ((:accl __accl) (instance geometry_msgs::Vector3 :init))
    ((:gyro __gyro) (instance geometry_msgs::Vector3 :init))
    ((:mag __mag) (instance geometry_msgs::Vector3 :init))
    )
   (send-super :init)
   (setq _accl __accl)
   (setq _gyro __gyro)
   (setq _mag __mag)
   self)
  (:accl
   (&rest __accl)
   (if (keywordp (car __accl))
       (send* _accl __accl)
     (progn
       (if __accl (setq _accl (car __accl)))
       _accl)))
  (:gyro
   (&rest __gyro)
   (if (keywordp (car __gyro))
       (send* _gyro __gyro)
     (progn
       (if __gyro (setq _gyro (car __gyro)))
       _gyro)))
  (:mag
   (&rest __mag)
   (if (keywordp (car __mag))
       (send* _mag __mag)
     (progn
       (if __mag (setq _mag (car __mag)))
       _mag)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Vector3 _accl
    (send _accl :serialization-length)
    ;; geometry_msgs/Vector3 _gyro
    (send _gyro :serialization-length)
    ;; geometry_msgs/Vector3 _mag
    (send _mag :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Vector3 _accl
       (send _accl :serialize s)
     ;; geometry_msgs/Vector3 _gyro
       (send _gyro :serialize s)
     ;; geometry_msgs/Vector3 _mag
       (send _mag :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Vector3 _accl
     (send _accl :deserialize buf ptr-) (incf ptr- (send _accl :serialization-length))
   ;; geometry_msgs/Vector3 _gyro
     (send _gyro :deserialize buf ptr-) (incf ptr- (send _gyro :serialization-length))
   ;; geometry_msgs/Vector3 _mag
     (send _mag :deserialize buf ptr-) (incf ptr- (send _mag :serialization-length))
   ;;
   self)
  )

(setf (get custom_msg::Nineaxis_sensor :md5sum-) "f88f64117d491e110b918a22793ff2a1")
(setf (get custom_msg::Nineaxis_sensor :datatype-) "custom_msg/Nineaxis_sensor")
(setf (get custom_msg::Nineaxis_sensor :definition-)
      "geometry_msgs/Vector3 accl
geometry_msgs/Vector3 gyro
geometry_msgs/Vector3 mag


================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
")



(provide :custom_msg/Nineaxis_sensor "f88f64117d491e110b918a22793ff2a1")


