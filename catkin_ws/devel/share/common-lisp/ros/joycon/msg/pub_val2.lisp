; Auto-generated. Do not edit!


(cl:in-package joycon-msg)


;//! \htmlinclude pub_val2.msg.html

(cl:defclass <pub_val2> (roslisp-msg-protocol:ros-message)
  ((theta
    :reader theta
    :initarg :theta
    :type cl:integer
    :initform 0)
   (r
    :reader r
    :initarg :r
    :type cl:float
    :initform 0.0))
)

(cl:defclass pub_val2 (<pub_val2>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pub_val2>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pub_val2)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name joycon-msg:<pub_val2> is deprecated: use joycon-msg:pub_val2 instead.")))

(cl:ensure-generic-function 'theta-val :lambda-list '(m))
(cl:defmethod theta-val ((m <pub_val2>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader joycon-msg:theta-val is deprecated.  Use joycon-msg:theta instead.")
  (theta m))

(cl:ensure-generic-function 'r-val :lambda-list '(m))
(cl:defmethod r-val ((m <pub_val2>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader joycon-msg:r-val is deprecated.  Use joycon-msg:r instead.")
  (r m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pub_val2>) ostream)
  "Serializes a message object of type '<pub_val2>"
  (cl:let* ((signed (cl:slot-value msg 'theta)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'r))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pub_val2>) istream)
  "Deserializes a message object of type '<pub_val2>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'theta) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'r) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pub_val2>)))
  "Returns string type for a message object of type '<pub_val2>"
  "joycon/pub_val2")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pub_val2)))
  "Returns string type for a message object of type 'pub_val2"
  "joycon/pub_val2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pub_val2>)))
  "Returns md5sum for a message object of type '<pub_val2>"
  "a801c0838fbcc9070f818be3d380d84a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pub_val2)))
  "Returns md5sum for a message object of type 'pub_val2"
  "a801c0838fbcc9070f818be3d380d84a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pub_val2>)))
  "Returns full string definition for message of type '<pub_val2>"
  (cl:format cl:nil "int32 theta~%float32 r~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pub_val2)))
  "Returns full string definition for message of type 'pub_val2"
  (cl:format cl:nil "int32 theta~%float32 r~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pub_val2>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pub_val2>))
  "Converts a ROS message object to a list"
  (cl:list 'pub_val2
    (cl:cons ':theta (theta msg))
    (cl:cons ':r (r msg))
))
