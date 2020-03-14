require 'find'


Find.find('.').select do |entry|
  entry.end_with? '.tex' and %r{aux-} !~ entry
end.each do |entry|
  contents = IO.read(entry)

  contents.gsub!( /documentclass{pvm-slides}/, 'documentclass{../ucll-slides}' )
  contents.gsub!( /documentclass\[handout\]{pvm-slides}/, 'documentclass[handout]{../ucll-slides}' )

  IO.write(entry, contents)
end
