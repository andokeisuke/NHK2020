; Auto-generated. Do not edit!


(cl:in-package joycon-msg)


;//! \htmlinclude pub_val.msg.html

(cl:defclass <pub_val> (roslisp-msg-protocol:ros-message)
  ((theta
    :reader theta
    :initarg :theta
    :type cl:integer
    :initform 0)
   (r
    :reader r
    :initarg :r
    :type cl:integer
    :initform 0))
)

(cl:defclass pub_val (<pub_val>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pub_val>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pub_val)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name joycon-msg:<pub_val> is deprecated: use joycon-msg:pub_val instead.")))

(cl:ensure-generic-function 'theta-val :lambda-list '(m))
(cl:defmethod theta-val ((m <pub_val>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader joycon-msg:theta-val is deprecated.  Use joycon-msg:theta instead.")
  (theta m))

(cl:ensure-generic-function 'r-val :lambda-list '(m))
(cl:defmethod r-val ((m <pub_val>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader joycon-msg:r-val is deprecated.  Use joycon-msg:r instead.")
  (r m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pub_val>) ostream)
  "Serializes a message object of type '<pub_val>"
  (cl:let* ((signed (cl:slot-value msg 'theta)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'r)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pub_val>) istream)
  "Deserializes a message object of type '<pub_val>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'theta) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'r) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pub_val>)))
  "Returns string type for a message object of type '<pub_val>"
  "joycon/pub_val")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pub_val)))
  "Returns string type for a message object of type 'pub_val"
  "joycon/pub_val")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pub_val>)))
  "Returns md5sum for a message object of type '<pub_val>"
  "58427f44aac94a7705da0eb1e5227372")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pub_val)))
  "Returns md5sum for a message object of type 'pub_val"
  "58427f44aac94a7705da0eb1e5227372")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pub_val>)))
  "Returns full string definition for message of type '<pub_val>"
  (cl:format cl:nil "int32 theta~%int32 r~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pub_val)))
  "Returns full string definition for message of type 'pub_val"
  (cl:format cl:nil "int32 theta~%int32 r~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pub_val>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pub_val>))
  "Converts a ROS message object to a list"
  (cl:list 'pub_val
    (cl:cons ':theta (theta msg))
    (cl:cons ':r (r msg))
))
