;; Auto-generated. Do not edit!


(when (boundp 'custom_msg::wh_msg)
  (if (not (find-package "CUSTOM_MSG"))
    (make-package "CUSTOM_MSG"))
  (shadow 'wh_msg (find-package "CUSTOM_MSG")))
(unless (find-package "CUSTOM_MSG::WH_MSG")
  (make-package "CUSTOM_MSG::WH_MSG"))

(in-package "ROS")
;;//! \htmlinclude wh_msg.msg.html


(defclass custom_msg::wh_msg
  :super ros::object
  :slots (_st_target_deg _st_now_deg _wh_target_vel _wh_now_vel ))

(defmethod custom_msg::wh_msg
  (:init
   (&key
    ((:st_target_deg __st_target_deg) 0.0)
    ((:st_now_deg __st_now_deg) 0.0)
    ((:wh_target_vel __wh_target_vel) 0.0)
    ((:wh_now_vel __wh_now_vel) 0.0)
    )
   (send-super :init)
   (setq _st_target_deg (float __st_target_deg))
   (setq _st_now_deg (float __st_now_deg))
   (setq _wh_target_vel (float __wh_target_vel))
   (setq _wh_now_vel (float __wh_now_vel))
   self)
  (:st_target_deg
   (&optional __st_target_deg)
   (if __st_target_deg (setq _st_target_deg __st_target_deg)) _st_target_deg)
  (:st_now_deg
   (&optional __st_now_deg)
   (if __st_now_deg (setq _st_now_deg __st_now_deg)) _st_now_deg)
  (:wh_target_vel
   (&optional __wh_target_vel)
   (if __wh_target_vel (setq _wh_target_vel __wh_target_vel)) _wh_target_vel)
  (:wh_now_vel
   (&optional __wh_now_vel)
   (if __wh_now_vel (setq _wh_now_vel __wh_now_vel)) _wh_now_vel)
  (:serialization-length
   ()
   (+
    ;; float64 _st_target_deg
    8
    ;; float64 _st_now_deg
    8
    ;; float64 _wh_target_vel
    8
    ;; float64 _wh_now_vel
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _st_target_deg
       (sys::poke _st_target_deg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _st_now_deg
       (sys::poke _st_now_deg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _wh_target_vel
       (sys::poke _wh_target_vel (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _wh_now_vel
       (sys::poke _wh_now_vel (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _st_target_deg
     (setq _st_target_deg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _st_now_deg
     (setq _st_now_deg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _wh_target_vel
     (setq _wh_target_vel (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _wh_now_vel
     (setq _wh_now_vel (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get custom_msg::wh_msg :md5sum-) "f89faf035737b3c1eab14ea32778c58c")
(setf (get custom_msg::wh_msg :datatype-) "custom_msg/wh_msg")
(setf (get custom_msg::wh_msg :definition-)
      "float64 st_target_deg
float64 st_now_deg
float64 wh_target_vel
float64 wh_now_vel

")



(provide :custom_msg/wh_msg "f89faf035737b3c1eab14ea32778c58c")


