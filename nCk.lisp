; You can run on the https://rextester.com/l/common_lisp_online_compiler.

(setq a '(1 2 3 4 5))

(defun permutation(n k a b)
  (cond
        ((eq k 0) (print b))
        ((eq n k)(progn
                  (setq b (append b (list(car a))))
                  (permutation (- n 1) (- k 1) (cdr a) b)
                  ))
        (t (progn
             (setq c (append b (list(car a))))
             (permutation (- n 1) (- k 1) (cdr a) c)
             (permutation (- n 1) k (cdr a) b)
             )
           )
        )
  )

(permutation (length a) 3 a nil)
