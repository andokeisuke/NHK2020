;; Auto-generated. Do not edit!


(when (boundp 'custom_msg::RL)
  (if (not (find-package "CUSTOM_MSG"))
    (make-package "CUSTOM_MSG"))
  (shadow 'RL (find-package "CUSTOM_MSG")))
(unless (find-package "CUSTOM_MSG::RL")
  (make-package "CUSTOM_MSG::RL"))

(in-package "ROS")
;;//! \htmlinclude RL.msg.html


(defclass custom_msg::RL
  :super ros::object
  :slots (_right _left ))

(defmethod custom_msg::RL
  (:init
   (&key
    ((:right __right) 0)
    ((:left __left) 0)
    )
   (send-super :init)
   (setq _right (round __right))
   (setq _left (round __left))
   self)
  (:right
   (&optional __right)
   (if __right (setq _right __right)) _right)
  (:left
   (&optional __left)
   (if __left (setq _left __left)) _left)
  (:serialization-length
   ()
   (+
    ;; int64 _right
    8
    ;; int64 _left
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _right
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _right (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _right) (= (length (_right . bv)) 2)) ;; bignum
              (write-long (ash (elt (_right . bv) 0) 0) s)
              (write-long (ash (elt (_right . bv) 1) -1) s))
             ((and (class _right) (= (length (_right . bv)) 1)) ;; big1
              (write-long (elt (_right . bv) 0) s)
              (write-long (if (>= _right 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _right s)(write-long (if (>= _right 0) 0 #xffffffff) s)))
     ;; int64 _left
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _left (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _left) (= (length (_left . bv)) 2)) ;; bignum
              (write-long (ash (elt (_left . bv) 0) 0) s)
              (write-long (ash (elt (_left . bv) 1) -1) s))
             ((and (class _left) (= (length (_left . bv)) 1)) ;; big1
              (write-long (elt (_left . bv) 0) s)
              (write-long (if (>= _left 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _left s)(write-long (if (>= _left 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _right
#+(or :alpha :irix6 :x86_64)
      (setf _right (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _right (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _left
#+(or :alpha :irix6 :x86_64)
      (setf _left (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _left (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(setf (get custom_msg::RL :md5sum-) "b18a642f9d124a9e6cb20a01284787da")
(setf (get custom_msg::RL :datatype-) "custom_msg/RL")
(setf (get custom_msg::RL :definition-)
      "int64 right
int64 left

")



(provide :custom_msg/RL "b18a642f9d124a9e6cb20a01284787da")


