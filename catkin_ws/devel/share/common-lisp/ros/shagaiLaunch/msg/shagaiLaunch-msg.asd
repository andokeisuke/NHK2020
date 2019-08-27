
(cl:in-package :asdf)

(defsystem "shagaiLaunch-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "shagaiLaunch_msg" :depends-on ("_package_shagaiLaunch_msg"))
    (:file "_package_shagaiLaunch_msg" :depends-on ("_package"))
  ))