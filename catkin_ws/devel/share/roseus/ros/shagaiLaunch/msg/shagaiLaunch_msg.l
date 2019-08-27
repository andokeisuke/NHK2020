;; Auto-generated. Do not edit!


(when (boundp 'shagaiLaunch::shagaiLaunch_msg)
  (if (not (find-package "SHAGAILAUNCH"))
    (make-package "SHAGAILAUNCH"))
  (shadow 'shagaiLaunch_msg (find-package "SHAGAILAUNCH")))
(unless (find-package "SHAGAILAUNCH::SHAGAILAUNCH_MSG")
  (make-package "SHAGAILAUNCH::SHAGAILAUNCH_MSG"))

(in-package "ROS")
;;//! \htmlinclude shagaiLaunch_msg.msg.html


(defclass shagaiLaunch::shagaiLaunch_msg
  :super ros::object
  :slots (_phase _action ))

(defmethod shagaiLaunch::shagaiLaunch_msg
  (:init
   (&key
    ((:phase __phase) 0)
    ((:action __action) "")
    )
   (send-super :init)
   (setq _phase (round __phase))
   (setq _action (string __action))
   self)
  (:phase
   (&optional __phase)
   (if __phase (setq _phase __phase)) _phase)
  (:action
   (&optional __action)
   (if __action (setq _action __action)) _action)
  (:serialization-length
   ()
   (+
    ;; int8 _phase
    1
    ;; string _action
    4 (length _action)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _phase
       (write-byte _phase s)
     ;; string _action
       (write-long (length _action) s) (princ _action s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _phase
     (setq _phase (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _phase 127) (setq _phase (- _phase 256)))
   ;; string _action
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _action (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get shagaiLaunch::shagaiLaunch_msg :md5sum-) "5d4369385089c16dc86085a13d1749a8")
(setf (get shagaiLaunch::shagaiLaunch_msg :datatype-) "shagaiLaunch/shagaiLaunch_msg")
(setf (get shagaiLaunch::shagaiLaunch_msg :definition-)
      "int8 phase
string action

")



(provide :shagaiLaunch/shagaiLaunch_msg "5d4369385089c16dc86085a13d1749a8")


