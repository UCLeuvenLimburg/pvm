STDIN.read.scan(/==== (.*?) ====(.*?)==== END ====/m).each do |filename, contents|
  File.open(filename, 'w') do |out|
    out.write contents
  end
end
