package=qrencode
$(package)_version=3.4.4
# $(package)_download_path=https://fukuchi.org/works/qrencode/
# https://ipfs.decenomy.net/Qma2igUXcx1UPLW2qhsxqx3Xjbi4F6ZaiGRxhb3Ef913cF?filename=qrencode-3.4.4.tar.bz2
$(package)_download_path=https://ipfs.decenomy.net
$(package)_download_file=Qma2igUXcx1UPLW2qhsxqx3Xjbi4F6ZaiGRxhb3Ef913cF
$(package)_file_name=$(package)-$($(package)_version).tar.bz2
$(package)_sha256_hash=efe5188b1ddbcbf98763b819b146be6a90481aac30cfc8d858ab78a19cde1fa5

define $(package)_set_vars
$(package)_config_opts=--disable-shared -without-tools --disable-sdltest
$(package)_config_opts_linux=--with-pic
endef

define $(package)_preprocess_cmds
  cp -f $(BASEDIR)/config.guess $(BASEDIR)/config.sub use
endef

define $(package)_config_cmds
  $($(package)_autoconf)
endef

define $(package)_build_cmds
  $(MAKE)
endef

define $(package)_stage_cmds
  $(MAKE) DESTDIR=$($(package)_staging_dir) install
endef
