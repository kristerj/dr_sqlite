# frozen_string_literal: true
include Colors

# Initiates loading hardware presets from hw.json
#
# @param args [Args] Generic Dragon Ruby arguments
# @return [VOID] Displays splash screen through set instance variable
def init_hw args
  @app.init_step +=1
end

# Initiates the application screen
#
# @param args (see #init_hw)
# @return [VOID] Displays main app screen through set instance variable
def init_misc args
  @app.activate(@app.main_screen)
  @app.init_step +=1
end

# Initiates loading hardware tags from tags.json
#
# @param args (see #init_hw)
# @return (see #init_hw)
def init_tags args
    @app.init_step +=1

end

# The main program loop
#
# @param args (see #init_hw)
# @return (see #init_misc)
def run args
  args.gtk.log_level = :off
  args.outputs.background_color = background_color
  args.state.blink_1s = @app.blink_1s
  args.state.blink_halfs = @app.blink_halfs
  $gtk.set_window_fullscreen $fullscreen

end

# Sets up the splash screen
#
# @param args (see #init_hw)
# @return (see #init_hw)
def splash args
  @app.init_step +=1
end

# main app tick method
#
# @param args [$gtk.args] DR plunks this args in
# @return [VOID]
def tick(args)
  if args.state.tick_count == 0
    @app = Application.new
    @app.init_step = 0 # in case of reset/reload
  end
  case @app.init_step
    when 0
      splash args
    when 1
      init_hw args
    when 2
      init_tags args
    when 3
      init_misc args
    else
      run args
  end

end


