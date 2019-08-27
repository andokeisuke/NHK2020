
(cl:in-package :asdf)

(defsystem "joycon-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "pub_val" :depends-on ("_package_pub_val"))
    (:file "_package_pub_val" :depends-on ("_package"))
    (:file "pub_val2" :depends-on ("_package_pub_val2"))
    (:file "_package_pub_val2" :depends-on ("_package"))
  ))