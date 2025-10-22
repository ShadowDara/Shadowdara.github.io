# Shortcut to start Jekyll

all: run

run:
#	$(MAKE) install
#	npm run build:css
	bundle exec jekyll serve

install:
	npm i

.PHONY: run
