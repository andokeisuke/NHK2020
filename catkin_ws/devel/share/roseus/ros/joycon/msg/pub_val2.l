;; Auto-generated. Do not edit!


(when (boundp 'joycon::pub_val2)
  (if (not (find-package "JOYCON"))
    (make-package "JOYCON"))
  (shadow 'pub_val2 (find-package "JOYCON")))
(unless (find-package "JOYCON::PUB_VAL2")
  (make-package "JOYCON::PUB_VAL2"))

(in-package "ROS")
;;//! \htmlinclude pub_val2.msg.html


(defclass joycon::pub_val2
  :super ros::object
  :slots (_theta _r ))

(defmethod joycon::pub_val2
  (:init
   (&key
    ((:theta __theta) 0)
    ((:r __r) 0.0)
    )
   (send-super :init)
   (setq _theta (round __theta))
   (setq _r (float __r))
   self)
  (:theta
   (&optional __theta)
   (if __theta (setq _theta __theta)) _theta)
  (:r
   (&optional __r)
   (if __r (setq _r __r)) _r)
  (:serialization-length
   ()
   (+
    ;; int32 _theta
    4
    ;; float32 _r
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _theta
       (write-long _theta s)
     ;; float32 _r
       (sys::poke _r (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _theta
     (setq _theta (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _r
     (setq _r (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get joycon::pub_val2 :md5sum-) "a801c0838fbcc9070f818be3d380d84a")
(setf (get joycon::pub_val2 :datatype-) "joycon/pub_val2")
(setf (get joycon::pub_val2 :definition-)
      "int32 theta
float32 r


")



(provide :joycon/pub_val2 "a801c0838fbcc9070f818be3d380d84a")


