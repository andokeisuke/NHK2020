;; Auto-generated. Do not edit!


(when (boundp 'joycon::pub_val)
  (if (not (find-package "JOYCON"))
    (make-package "JOYCON"))
  (shadow 'pub_val (find-package "JOYCON")))
(unless (find-package "JOYCON::PUB_VAL")
  (make-package "JOYCON::PUB_VAL"))

(in-package "ROS")
;;//! \htmlinclude pub_val.msg.html


(defclass joycon::pub_val
  :super ros::object
  :slots (_theta _r ))

(defmethod joycon::pub_val
  (:init
   (&key
    ((:theta __theta) 0)
    ((:r __r) 0)
    )
   (send-super :init)
   (setq _theta (round __theta))
   (setq _r (round __r))
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
    ;; int32 _r
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _theta
       (write-long _theta s)
     ;; int32 _r
       (write-long _r s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _theta
     (setq _theta (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _r
     (setq _r (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get joycon::pub_val :md5sum-) "58427f44aac94a7705da0eb1e5227372")
(setf (get joycon::pub_val :datatype-) "joycon/pub_val")
(setf (get joycon::pub_val :definition-)
      "int32 theta
int32 r

")



(provide :joycon/pub_val "58427f44aac94a7705da0eb1e5227372")


