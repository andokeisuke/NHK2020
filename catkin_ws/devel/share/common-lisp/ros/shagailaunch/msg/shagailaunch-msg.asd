
(cl:in-package :asdf)

(defsystem "shagailaunch-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "shagailaunch_msg" :depends-on ("_package_shagailaunch_msg"))
    (:file "_package_shagailaunch_msg" :depends-on ("_package"))
  ))