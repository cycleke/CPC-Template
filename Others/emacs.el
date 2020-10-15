(defun myc++ ()
  (c-set-style "stroustrup")
  (setq tab-width 2)
  (setq indent-tabs-mode nil)
  (setq c-basic-offset 2)
  (c-toggle-hungry-state)
  (defun compile-and-run()
    (interactive)
    (let (file-name (file-name-sans-extension (file-name-nondirectory buffer-file-name))))
    (compile
     (format "g++ %s.cpp -o %s -Wall -Wextra -Wshadow -O2 && %s.exe"
             file-name file-name file-name)))
  (local-set-key (kbd "C-c C-c") 'compile-and-run)
  (local-set-key (kbd "C-c C-k") 'kill-compilation))
(add-hook 'c++-mode-hook 'myc++)

(global-set-key [(meta ?o)] 'other-window)
(global-set-key [(meta ?/)] 'hippie-expand)
(global-set-key [(control tab)] ' senator-completion-menu-popup)
(setq hippie-expand-try-functions-list
      '(try-expand-dabbrev
        try-expand-dabbrev-visible
        try-expand-dabbrev-all-buffers
        try-expand-dabbrev-from-kill
        try-complete-file-name-partially
        try-complete-file-name
        try-expand-all-abbrevs
        try-expand-list
        try-expand-line))

(setq auto-save-mode nil)
(setq make-backup-files nil)

(ido-mode t)
(show-paren-mode 1)
(delete-selection-mode t)
(global-linum-mode t)
(global-auto-revert-mode t)
