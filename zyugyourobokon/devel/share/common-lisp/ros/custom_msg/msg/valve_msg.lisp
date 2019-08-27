; Auto-generated. Do not edit!


(cl:in-package custom_msg-msg)


;//! \htmlinclude valve_msg.msg.html

(cl:defclass <valve_msg> (roslisp-msg-protocol:ros-message)
  ((state
    :reader state
    :initarg :state
    :type cl:boolean
    :initform cl:nil)
   (valve_number
    :reader valve_number
    :initarg :valve_number
    :type cl:fixnum
    :initform 0))
)

(cl:defclass valve_msg (<valve_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <valve_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'valve_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msg-msg:<valve_msg> is deprecated: use custom_msg-msg:valve_msg instead.")))

(cl:ensure-generic-function 'state-val :lambda-list '(m))
(cl:defmethod state-val ((m <valve_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:state-val is deprecated.  Use custom_msg-msg:state instead.")
  (state m))

(cl:ensure-generic-function 'valve_number-val :lambda-list '(m))
(cl:defmethod valve_number-val ((m <valve_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:valve_number-val is deprecated.  Use custom_msg-msg:valve_number instead.")
  (valve_number m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <valve_msg>) ostream)
  "Serializes a message object of type '<valve_msg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'state) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'valve_number)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <valve_msg>) istream)
  "Deserializes a message object of type '<valve_msg>"
    (cl:setf (cl:slot-value msg 'state) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'valve_number) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<valve_msg>)))
  "Returns string type for a message object of type '<valve_msg>"
  "custom_msg/valve_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'valve_msg)))
  "Returns string type for a message object of type 'valve_msg"
  "custom_msg/valve_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<valve_msg>)))
  "Returns md5sum for a message object of type '<valve_msg>"
  "f60ba44565f980103448a6708624440b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'valve_msg)))
  "Returns md5sum for a message object of type 'valve_msg"
  "f60ba44565f980103448a6708624440b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<valve_msg>)))
  "Returns full string definition for message of type '<valve_msg>"
  (cl:format cl:nil "bool state~%int8 valve_number~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'valve_msg)))
  "Returns full string definition for message of type 'valve_msg"
  (cl:format cl:nil "bool state~%int8 valve_number~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <valve_msg>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <valve_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'valve_msg
    (cl:cons ':state (state msg))
    (cl:cons ':valve_number (valve_number msg))
))
