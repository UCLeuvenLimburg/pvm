const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');


module.exports = {
    entry: './index.tsx',
    resolve: {
        extensions: [ '.js', '.ts', '.tsx' ]
    },
    output: {
        path: path.join(__dirname, '../dist'),
        filename: 'overview-bundle.js'
    },
    module: {
        rules: [
            {
                test: /\.tsx?$/,
                loader: 'ts-loader'
            }
        ]
    },
    plugins: [
        new HtmlWebpackPlugin({
            template: './index.html'
        })
    ]
};
