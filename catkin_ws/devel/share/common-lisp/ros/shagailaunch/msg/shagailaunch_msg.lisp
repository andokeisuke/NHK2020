; Auto-generated. Do not edit!


(cl:in-package shagailaunch-msg)


;//! \htmlinclude shagailaunch_msg.msg.html

(cl:defclass <shagailaunch_msg> (roslisp-msg-protocol:ros-message)
  ((phase
    :reader phase
    :initarg :phase
    :type cl:fixnum
    :initform 0)
   (action
    :reader action
    :initarg :action
    :type cl:string
    :initform ""))
)

(cl:defclass shagailaunch_msg (<shagailaunch_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <shagailaunch_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'shagailaunch_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name shagailaunch-msg:<shagailaunch_msg> is deprecated: use shagailaunch-msg:shagailaunch_msg instead.")))

(cl:ensure-generic-function 'phase-val :lambda-list '(m))
(cl:defmethod phase-val ((m <shagailaunch_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader shagailaunch-msg:phase-val is deprecated.  Use shagailaunch-msg:phase instead.")
  (phase m))

(cl:ensure-generic-function 'action-val :lambda-list '(m))
(cl:defmethod action-val ((m <shagailaunch_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader shagailaunch-msg:action-val is deprecated.  Use shagailaunch-msg:action instead.")
  (action m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <shagailaunch_msg>) ostream)
  "Serializes a message object of type '<shagailaunch_msg>"
  (cl:let* ((signed (cl:slot-value msg 'phase)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'action))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'action))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <shagailaunch_msg>) istream)
  "Deserializes a message object of type '<shagailaunch_msg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'phase) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'action) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'action) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<shagailaunch_msg>)))
  "Returns string type for a message object of type '<shagailaunch_msg>"
  "shagailaunch/shagailaunch_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'shagailaunch_msg)))
  "Returns string type for a message object of type 'shagailaunch_msg"
  "shagailaunch/shagailaunch_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<shagailaunch_msg>)))
  "Returns md5sum for a message object of type '<shagailaunch_msg>"
  "5d4369385089c16dc86085a13d1749a8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'shagailaunch_msg)))
  "Returns md5sum for a message object of type 'shagailaunch_msg"
  "5d4369385089c16dc86085a13d1749a8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<shagailaunch_msg>)))
  "Returns full string definition for message of type '<shagailaunch_msg>"
  (cl:format cl:nil "int8 phase~%string action~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'shagailaunch_msg)))
  "Returns full string definition for message of type 'shagailaunch_msg"
  (cl:format cl:nil "int8 phase~%string action~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <shagailaunch_msg>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'action))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <shagailaunch_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'shagailaunch_msg
    (cl:cons ':phase (phase msg))
    (cl:cons ':action (action msg))
))
