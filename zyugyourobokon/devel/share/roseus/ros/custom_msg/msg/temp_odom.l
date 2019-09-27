;; Auto-generated. Do not edit!


(when (boundp 'custom_msg::temp_odom)
  (if (not (find-package "CUSTOM_MSG"))
    (make-package "CUSTOM_MSG"))
  (shadow 'temp_odom (find-package "CUSTOM_MSG")))
(unless (find-package "CUSTOM_MSG::TEMP_ODOM")
  (make-package "CUSTOM_MSG::TEMP_ODOM"))

(in-package "ROS")
;;//! \htmlinclude temp_odom.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass custom_msg::temp_odom
  :super ros::object
  :slots (_position _velocity ))

(defmethod custom_msg::temp_odom
  (:init
   (&key
    ((:position __position) (instance geometry_msgs::Vector3 :init))
    ((:velocity __velocity) (instance geometry_msgs::Vector3 :init))
    )
   (send-super :init)
   (setq _position __position)
   (setq _velocity __velocity)
   self)
  (:position
   (&rest __position)
   (if (keywordp (car __position))
       (send* _position __position)
     (progn
       (if __position (setq _position (car __position)))
       _position)))
  (:velocity
   (&rest __velocity)
   (if (keywordp (car __velocity))
       (send* _velocity __velocity)
     (progn
       (if __velocity (setq _velocity (car __velocity)))
       _velocity)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Vector3 _position
    (send _position :serialization-length)
    ;; geometry_msgs/Vector3 _velocity
    (send _velocity :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Vector3 _position
       (send _position :serialize s)
     ;; geometry_msgs/Vector3 _velocity
       (send _velocity :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Vector3 _position
     (send _position :deserialize buf ptr-) (incf ptr- (send _position :serialization-length))
   ;; geometry_msgs/Vector3 _velocity
     (send _velocity :deserialize buf ptr-) (incf ptr- (send _velocity :serialization-length))
   ;;
   self)
  )

(setf (get custom_msg::temp_odom :md5sum-) "589dbd8c358d253de2ab5441acd36a2b")
(setf (get custom_msg::temp_odom :datatype-) "custom_msg/temp_odom")
(setf (get custom_msg::temp_odom :definition-)
      "geometry_msgs/Vector3 position
geometry_msgs/Vector3 velocity


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



(provide :custom_msg/temp_odom "589dbd8c358d253de2ab5441acd36a2b")

