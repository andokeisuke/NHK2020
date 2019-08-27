;; Auto-generated. Do not edit!


(when (boundp 'custom_msg::valve_msg)
  (if (not (find-package "CUSTOM_MSG"))
    (make-package "CUSTOM_MSG"))
  (shadow 'valve_msg (find-package "CUSTOM_MSG")))
(unless (find-package "CUSTOM_MSG::VALVE_MSG")
  (make-package "CUSTOM_MSG::VALVE_MSG"))

(in-package "ROS")
;;//! \htmlinclude valve_msg.msg.html


(defclass custom_msg::valve_msg
  :super ros::object
  :slots (_state _valve_number ))

(defmethod custom_msg::valve_msg
  (:init
   (&key
    ((:state __state) nil)
    ((:valve_number __valve_number) 0)
    )
   (send-super :init)
   (setq _state __state)
   (setq _valve_number (round __valve_number))
   self)
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:valve_number
   (&optional __valve_number)
   (if __valve_number (setq _valve_number __valve_number)) _valve_number)
  (:serialization-length
   ()
   (+
    ;; bool _state
    1
    ;; int8 _valve_number
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _state
       (if _state (write-byte -1 s) (write-byte 0 s))
     ;; int8 _valve_number
       (write-byte _valve_number s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _state
     (setq _state (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int8 _valve_number
     (setq _valve_number (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _valve_number 127) (setq _valve_number (- _valve_number 256)))
   ;;
   self)
  )

(setf (get custom_msg::valve_msg :md5sum-) "f60ba44565f980103448a6708624440b")
(setf (get custom_msg::valve_msg :datatype-) "custom_msg/valve_msg")
(setf (get custom_msg::valve_msg :definition-)
      "bool state
int8 valve_number

")



(provide :custom_msg/valve_msg "f60ba44565f980103448a6708624440b")


