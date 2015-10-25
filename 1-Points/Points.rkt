#lang racket
(define (relocate current-x current-y str)
  (define (helper k i x y)
    (if (= (remainder k 2) 0)
        (cond
    [(= i ( string-length str)) (string-append "(" (number->string x) "," (number->string y) ")")]
    [(string=? (~a (string-ref str i)) ">") (helper k (+ i 1) (+ x 1) y)]
    [(string=? (~a (string-ref str i)) "<") (helper k (+ i 1) (- x 1) y)]
    [(string=? (~a (string-ref str i)) "^") (helper k (+ i 1) x (- y 1))]
    [(string=? (~a (string-ref str i)) "v") (helper k (+ i 1) x (+ y 1))]
    [(string=? (~a (string-ref str i)) "~") (helper (+ k 1) (+ i 1) x y)])
         (cond
    [(= i ( string-length str)) (string-append "(" (number->string x) "," (number->string y) ")")]
    [(string=? (~a (string-ref str i)) ">") (helper k (+ i 1) (- x 1) y)]
    [(string=? (~a (string-ref str i)) "<") (helper k (+ i 1) (+ x 1) y)]
    [(string=? (~a (string-ref str i)) "^") (helper k (+ i 1) x (+ y 1))]
    [(string=? (~a (string-ref str i)) "v") (helper k (+ i 1) x (- y 1))]
    [(string=? (~a (string-ref str i)) "~") (helper (+ k 1) (+ i 1) x y)])))
  (helper 0 0 current-x current-y))
