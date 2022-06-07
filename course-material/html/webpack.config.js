const path = require('path');
const webpack = require('webpack');

if ( !("LAB" in process.env) )
{
    throw new Error('No lab defined! Set environment variable LAB');
}

const lab_id = process.env['LAB'];
const inputPath = path.join("src", lab_id);
const outputPath = path.join("dist", lab_id);


function chapter()
{
    const files = [
        path.resolve('.', inputPath, 'lab.tsx'),
        path.resolve('.', inputPath, 'lab.html'),
    ];

    return {
        entry: files,
        output: {
            path: path.resolve(__dirname, outputPath),
            filename: 'bundle.js'
        },
        optimization: {
            minimize: false
        },
        module: {
            rules: [
                {
                    test: /\.html$/,
                    use: [
                        {
                            loader: 'file-loader',
                            options: { name: 'lab.html' }
                        },
                    ]
                },
                {
                    test: /\.tsx?$/,
                    use: { loader: 'ts-loader' },
                    exclude: /node_modules/,
                    include: [
                        path.resolve('.', inputPath)
                    ]
                },
             ]
        },
        resolve: { extensions: ['.ts', '.tsx', '.js'] },
    };
}


module.exports = function(env, argv)
{
    return chapter();
}
